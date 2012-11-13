class MyGame_Game < Spinel_Game
  attr_accessor :name
  
  def update
    puts 'MyGame_Game#update called'
    renderer.draw
  end
end