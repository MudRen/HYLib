//room: /d/tangmen/jiaolou1.c
//  by hem
inherit ROOM;

void create()
{
  set("short","������¥");
  set("long",
      "�����Ƽұ���������¥�������������Ժգ������Ӵ󣬵���Ҳ���в��١�\n"
      "Ϊ�����ͻϮ���������ܶ��������Ľ�¥����һ����ʿ�����Ѳ�ߡ�\n"
     );

  set("exits",([
       
	"westdown" : __DIR__"huayuan8",
	
	]));
        set("objects", ([
		__DIR__"npc/huzuwushi" : 4,
	]));

 setup();
 replace_program(ROOM);
}




