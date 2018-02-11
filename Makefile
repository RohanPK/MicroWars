.PHONY: clean All

All:
	@echo "----------Building project:[ MicroWars - Debug ]----------"
	@cd "MicroWars" && "$(MAKE)" -f  "MicroWars.mk"
clean:
	@echo "----------Cleaning project:[ MicroWars - Debug ]----------"
	@cd "MicroWars" && "$(MAKE)" -f  "MicroWars.mk" clean
