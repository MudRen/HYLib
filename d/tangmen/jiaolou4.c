//room: /d/tangmen/jiaolou4.c
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
       
	"westdown" : __DIR__"xiaoxiao-lou",
	
	]));
	set("objects", ([
		__DIR__"npc/yingzuwushi" : 4,
	]));

 setup();
 replace_program(ROOM);
}




