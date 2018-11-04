//room: /d/tangmen/jiaolou7.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","东南角楼");
  set("long",
      "这是唐家堡的了望角楼。唐门虽声名显赫，势力庞大，但是也树敌不少。\n"
      "为防外敌突袭，所以四周都有这样的角楼。有一队武士在这儿巡逻。\n"
     );

  set("exits",([
       
	"westdown" : __DIR__"wumiange",
	
	]));
	set("objects", ([
		__DIR__"npc/jiuzuwushi" : 4,
	]));

 setup();
 replace_program(ROOM);
}




