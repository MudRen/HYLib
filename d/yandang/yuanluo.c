// Room: /d/yandang/yuanluo.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "Ժ��");
  set ("long", @LONG
������ܽ�ؿ�ջ��Ժ��,�м���һ����ש·,·��������������,��
�ż���÷��,���濿��Ժǽ��һ������,�����߷ֱ������ȥ,���ǵ���
�Ŀͷ���,����Ů��,�ɱ�����.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/sunerniang.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"kezhan",
  "north" : __DIR__"nvkefang",
  "south" : __DIR__"nankefang",
]));
  set("outdoors", "/d/yandang");

  setup();
}
int valid_leave(object me,string dir)
{
	object npc;

	npc=present("sun erniang",this_object());
	if(dir=="out")	{
		if( me->query_temp("rent_paid"))	me->delete_temp("rent_paid");
		return ::valid_leave(me,dir);
	}	

	if((me->query("gender")=="����"&&dir=="north")||(me->query("gender")=="Ů��"&&dir=="south")) {
	return notify_fail("��������򣡣�\n");
	}
	if (!me->query("rend_paid") && objectp(npc))  {
	return notify_fail("����������ס���ȸ�����������������ѵ�����ͼ���ɡ�\n"); 
	}
	return ::valid_leave(me,dir);
}

