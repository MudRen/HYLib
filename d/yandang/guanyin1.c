// Room: /d/yandang/guanyin1.c

inherit ROOM;

void create()
{
	set("short", "�ڶ���");
	set("long", @LONG
�ڶ�����������,�������'��,��,��,˳'�Ĵ�����.�����ο�����,
ֻ����������������,��˵���������ֳƻ������Ĵ���,������Ϊ��
������,��������,��Ŀ����,��������.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  //__DIR__"npc/heshang1" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin2",
  "down" : __DIR__"guanyin",
]));

	setup();
}
int valid_leave(object me,string dir)
{
  object ob;
 ob=present("hua yan",this_object());
if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
    return notify_fail("������ס��:����ұ������,��Ϊ�������ȥ!\n");
       }
return ::valid_leave(me,dir);
}