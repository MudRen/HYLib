//room: /d/tangmen/jiaolou5.c
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
       
	"eastdown" : __DIR__"zhawujian",
	
	]));
	set("objects", ([
		__DIR__"npc/yaozuwushi" : 4,
	]));

 setup();
 replace_program(ROOM);
}




