// Room: /d/ruzzhou/yinyuan-tang.c    ����֮��
// by llm 99/06

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��Ե��");
   set("long", @LONG
���ֱ�߽���һƬ��ɫ�����磬�ߵ����ҵش��Ÿ�ʽ�����ĺ��籶�
��ֽ������ϸϸ��ȥ��ÿһ������������ԧ���ˣ�͸��һ�ɹ�Ũ����ϲ
�����գ�����һ����ң�
          ǧ����Եһ��ǣ
LONG
   );
	set("exits", ([
		"west" : __DIR__"hongniang-zhuang",
   ]) );
   set("objects", ([
   ]) );
   set("no_fight",1);
   set("no_steal",1);
   set("no_beg",1);
   set("no_sleep_room",1);

   setup();
	replace_program(ROOM);
}
