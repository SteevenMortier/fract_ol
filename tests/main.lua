function love.keypressed(k)
   if k == 'escape' then
      love.event.quit()
   end
   if k == '=' then
	  zoom = zoom + 10
      iteration_max = iteration_max + 5
   end
   if k == '-' then
	  zoom = zoom - 10
      iteration_max = iteration_max - 5
   end
end

function	love.load()
    widht = love.graphics.getWidth()
    height = love.graphics.getHeight()
    iteration_max = 50
    zoom = 100 -- pour une distance de 1 sur le plan, on a 100 pixel sur l'image
end

function	love.update()
    c = 0
    z = 0
    i = 0
end



function	love.draw()
    x1 = -2.1
    x2 = 0.6
    y1 = -1.2
    y2 = 1.2

    image_x = (x2 - x1) * zoom
    image_y = (y2 - y1) * zoom

    for x = 0, image_x do --par pas de 1
        for y = 0,  image_y do --par pas de 1
            c_r = x / zoom + x1
            c_i = y / zoom + y1
            z_r = 0
            z_i = 0
            i = 0
            while (z_r*z_r + z_i*z_i < 4 and i < iteration_max) do
                tmp = z_r
                z_r = z_r * z_r - z_i * z_i + c_r
                z_i = 2 * z_i * tmp + c_i
                i = i + 1
            end

            if i == iteration_max then
                --dessiner en noir le pixel de coordonné (x; x)
                love.graphics.setColor(1, 1, 1)
                love.graphics.rectangle('fill', x, y, 1, 1)
            else
                love.graphics.setColor(0, 0, i / 10)
                love.graphics.rectangle('fill', x, y, 1, 1)
                --dessiner avec couleur rgb(0, 0, i*255/iterations_max) le pixel de coordonné (x; x)
            end
        end
    end
end
