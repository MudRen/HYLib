// Room: /d/yandang/guanyin2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ϵ�����,��͸��ܵ�����Ʈ����������˿.̧ͷ��,��һ��Ȫˮ
�Ӷ�������,��������,������������,����ͷ�,���������˼�,�����
����������Ȫ��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"guanyin1",
  "up" : __DIR__"guanyin3",
]));
	set("objects", ([ /* sizeof() == 1 */
  //__DIR__"npc/heshang2" : 1,
]));

	setup();

}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("jing ji",this_object());
if (objectp(ob)&&dir=="up")  {
  if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("������ס��:���������ͬ����ְ�?\n");
   }
 return ::valid_leave(me,dir);
}