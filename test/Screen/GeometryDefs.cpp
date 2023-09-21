#include "Screen/GeometryDefs.h"

#include "Wire.h"
#include "SH1106.h"

Geometry::Geometry(const std::vector<Point3D>& vertices, const std::vector<Edge>& edges)
: vertices(vertices), edges(edges) {}

Point3D Geometry::rotatePoint(const Point3D& point, double angleX, double angleY, double angleZ) const
{
    double sinX = sin(angleX);
    double cosX = cos(angleX);
    double sinY = sin(angleY);
    double cosY = cos(angleY);
    double sinZ = sin(angleZ);
    double cosZ = cos(angleZ);

    double dx = point.x * cosY * cosZ - point.y * cosY * sinZ + point.z * sinY;
    double dy = point.x * (sinX * sinY * cosZ + cosX * sinZ) + point.y * (cosX * cosZ - sinX * sinY * sinZ) - point.z * sinX * cosY;
    double dz = point.x * (sinX * sinZ - cosX * sinY * cosZ) + point.y * (cosX * sinY * cosZ + sinX * sinZ) + point.z * cosX * cosY;

    return {dx, dy, dz};
}

Point2D Geometry::projectPoint(const Point3D& point) const
{
    return {static_cast<int16_t>(64 + point.x * 30), static_cast<int16_t>(32 - point.y * 30)};
}

void Geometry::draw(SH1106& screen, double angleX, double angleY, double angleZ) const
{
    std::vector<Point2D> projectedVertices(vertices.size());

    for (size_t i = 0; i < vertices.size(); ++i)
    {
        Point3D rotatedPoint = rotatePoint(vertices[i], angleX, angleY, angleZ);
        projectedVertices[i] = projectPoint(rotatedPoint);
    }

    for (const Edge& edge : edges)
    {
        screen.drawLine(
            projectedVertices[edge.v1].x, projectedVertices[edge.v1].y,
            projectedVertices[edge.v2].x, projectedVertices[edge.v2].y
        );
    }
}
