//room: /d/tangmen/jiaolou6.c
//  xws 1998/11/05
inherit ROOM;

void create()
{
  set("short","�Ͻ�¥");
  set("long",
      "�����Ƽұ���������¥�������������Ժգ������Ӵ󣬵���Ҳ���в��١�\n"
      "Ϊ�����ͻϮ���������ܶ��������Ľ�¥����һ����ʿ�����Ѳ�ߡ�\n"
     );

  set("exits",([
       
	"down" : __DIR__"guajiantang",
	
	]));
	set("objects", ([
		__DIR__"npc/quanzuwushi" : 4,
	]));

 setup();
 replace_program(ROOM);
}




