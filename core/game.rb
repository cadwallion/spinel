class Spinel_Game
  attr_reader :renderer, :state_manager
  def initialize
    @renderer = Spinel_Renderer.new self
    @state_manager = Spinel_StateManager.new self
  end
    
  def renderer
    @renderer
  end
    
  def state_manager
    @state_manager
  end
end