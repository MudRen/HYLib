// Room: /d/yandang/guanyin3.c

inherit ROOM;

void create ()
{
  set ("short", "���Ĳ�");
  set ("long", @LONG
�������Ĳ�,���㾪����Ǵ˴���һ����ˮ��,��ˮ����,ˮ�е���
������������Ϸ,���Ƿ��ŷ�����.ÿ����¶�,�˴����ɻ�ר�����ַ�
��,��������.
LONG);

  set("objects", ([ /* sizeof() == 1 */
 // __DIR__"npc/heshang3.c" : 1,
]));
  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin4",
  "down" : __DIR__"guanyin2",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("cheng guan",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("�ι�������ס��.\n");
           }
return ::valid_leave(me,dir);
}
