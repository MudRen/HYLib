// Room: /d/yandang/guanyin5.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
�ϵ�������,���Ȼ���ִ˴���һ������,�������е�ɮ��ƽʱ��ס
����,��ĺ����,�������,���˼������֮���һ������,���������Ϲ�
�ŵ�һյ�͵�أ�����ŵ�����.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  //__DIR__"npc/heshang5.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin6",
  "down" : __DIR__"guanyin4",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("guan zheng",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("��֤������ס��.\n");
           }
return ::valid_leave(me,dir);
}
