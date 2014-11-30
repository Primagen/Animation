/**
 * Header for organizing some of the constants
 * that various parts of the program use
 */
namespace values {
  const double Pi = 3.14159265358979323851280895940618620443274267017841339111328125;
  const double Sqrt2 = 1.41421356237309504880168872420969807856967187537694807317667973799;
}

namespace strings {
  const std::string Separate        ( "[Separate]"  );
  const std::string Connected       ( "[Connected]" );
  const std::string Line            ( "[Line]"      );
  const std::string BezierQuadratic ( "[Bezier2]"   );
  const std::string BezierCubic     ( "[Bezier3]"   );
  const std::string Circle          ( "[Circle]"    );
  const std::string Ellipse         ( "[Ellipse]"   );
}


#elif ANIMATION_TEST == 8
/**
 *  8. Vector graphics test #2
 *   Creates and renders a bunch of random Quadratic Bezier Curves
 */
int main()
{
    srand(time(NULL));
    const unsigned Width  = 1366; //500;
    const unsigned Height =  768; //500;
    const Coordinate c1(0, 0);
    const Coordinate c2(Width/2, Height);
    const Coordinate c3(3*Width/4, Height/4);

    // Let's try this out...
    ///std::vector<Coordinate> line1 = {c1, c2    };
    ///std::vector<Coordinate> line2 = {c2, c3    };
    ///std::vector<Coordinate> bezr1 = {c3, c2, c1};
    
    std::vector<VectorGraphic> graphics;
    for (int i = 0; i < 1000; i++)
    {
        std::vector<Coordinate> random_bezier = {
            Coordinate(rand()%(2*Width), 2*rand()%(2*Height)),
            Coordinate(rand()%(2*Width), 2*rand()%(2*Height)),
            Coordinate(rand()%(2*Width), 2*rand()%(2*Height))
        };
        //TODO: emplace_back
        graphics.push_back(VectorGraphic(strings::BezierQuadratic, random_bezier));
    }

    // Specify what you want to add the list of coordinates as:
    ///graphics.push_back(VectorGraphic(strings::Line,            line1));
    ///graphics.push_back(VectorGraphic(strings::Line,            line2));
    ///graphics.push_back(VectorGraphic(strings::BezierQuadratic, bezr1));

    render("vector_images/vector_graphics_random.png", graphics, Width, Height, Color::Blue);
    std::cout << "vector graphic rendered to file." << std::endl;
}

#endif // ANIMATION_TEST
