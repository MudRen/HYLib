//Room: songlin4.c ����
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
������������������գ�������ֻ�о�������ǰ�󵽴�
������Ӱ��������һ�����������ã�������ӫӫ���׹⡣�㾪
��֮�䣬һ�Ų��ڸ����������ϣ�
LONG);
      set("objects", ([
           __DIR__"npc/xiao_louluo": 2,
"quest/skills2/wunon/non/nontian" : 1,
	])); 
    set_temp("wayao2",2);

      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "south"  : __DIR__"songlin2",
      ]));
//      set("no_clean_up", 0);
      set_temp("wayao1",1);
      setup();
      replace_program(ROOM);
}
