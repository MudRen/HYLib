// Room: /d/yandang/guanyin7
inherit ROOM;

void create ()
{
  set ("short", "�ڰ˲�");
  set ("long", @LONG
�ڰ˲㹩�����ҩʦ��,��˵��λ��������尲��,�ϼ�ƽ��,��
��������Ļ��Ǻܶ�,����ǰ�Ĵ���¯��������,�������Ƶ�����,����
���Ҳ��������һ�����ص�������.
LONG);

  set("objects", ([ /* sizeof() == 1 */
//__DIR__"npc/heshang7.c":1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin8",
  "down" : __DIR__"guanyin6",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("da bei",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("��������ס��.\n");
           }
return ::valid_leave(me,dir);
}
