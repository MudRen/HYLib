//room: /d/tangmen/jiaolou7.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","���Ͻ�¥");
  set("long",
      "�����Ƽұ���������¥�������������Ժգ������Ӵ󣬵���Ҳ���в��١�\n"
      "Ϊ�����ͻϮ���������ܶ��������Ľ�¥����һ����ʿ�����Ѳ�ߡ�\n"
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




