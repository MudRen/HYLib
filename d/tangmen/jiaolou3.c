//room: /d/tangmen/jiaolou3.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","����¥");
  set("long",
      "�����Ƽұ���������¥�������������Ժգ������Ӵ󣬵���Ҳ���в��١�\n"
      "Ϊ�����ͻϮ���������ܶ��������Ľ�¥����һ����ʿ�����Ѳ�ߡ�\n"
     );

  set("exits",([
       
	"eastdown" : __DIR__"qulang3",
	
	]));
	set("objects", ([
		__DIR__"npc/baozuwushi" : 4,
	]));

 setup();
 replace_program(ROOM);
}




