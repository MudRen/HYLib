// Room: /d/yandang/guanyin6.c

inherit ROOM;

void create ()
{
  set ("short", "���߲�");
  set ("long", @LONG
�����ĵ��߲㻹��һ��ի��,ÿ������Ӧ��ի,�Ӵ˴����������
�ڿ�,����ɼ�һָ����,���пɼ����������,����ɼ��ز�����.����
���,�ɼ���������.
LONG);

  set("objects", ([ /* sizeof() == 1 */
 // __DIR__"npc/heshang6" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin7",
  "down" : __DIR__"guanyin5",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("jue fei",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("����������ס��.\n");
           }
return ::valid_leave(me,dir);
}