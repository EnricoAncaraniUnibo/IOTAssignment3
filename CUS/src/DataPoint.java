
class DataPoint {
	private double waterLevel;
	private int valveValue;
	private String state;
	
	public DataPoint(double water, int valve, String state) {
		this.waterLevel = water;
		this.valveValue = valve;
		this.state = state;
	}
	
	public double getWaterLevel() {
		return waterLevel;
	}
	
	public long getValveValue() {
		return valveValue;
	}
	
	public String getState() {
		return state;
	}
}
