// Room: /d/yandang/guanyin4.c

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG
����㾰ɫ���,���Ƚ������������ǴӸ��ζ���ʯ�������µ�
��ˮ��,��һ�������ŵ�����,�����ʯ��Ȫ��.��������,�п�һС��,
��һ�����к��,��һ����.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  //__DIR__"npc/heshang4.c" : 1,
]));
  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin5",
  "down" : __DIR__"guanyin3",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("hui ming",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("����������ס��.\n");
           }
return ::valid_leave(me,dir);
}