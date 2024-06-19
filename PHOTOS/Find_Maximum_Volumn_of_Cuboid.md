
## Find Maximum Valumn Of Cuboid
### https://www.geeksforgeeks.org/problems/magical-box5306/1

![alt text](/PHOTOS/Photo/IMG20240619213759.jpg)
![alt text](/PHOTOS/Photo/IMG20240619213808.jpg)



### Code
        double maxVolume(double p, double a) {
                
                double l = (p - sqrt(p*p - 24 * a))/12;
            
                double v = (l*l*p - 8*l*l*l)/4;
                
                return v;
            }
        };
....