// Room: /d/japan/shuwu
inherit ROOM;

void create ()
{
  set ("short", "��Ұ����");
  set ("long", @LONG
��Ұ�������񻧸�����������,���žͿ�����ǽ��������������,ֻ
Ҫ�㱨������.�ϰ�����ҵ���Ҫ����.����໹�ǴӸ������ڵ���!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiedaos2",
]));
        set("objects", ([ /* sizeof() == 2 */
               __DIR__"npc/shantian" : 1,
            ]));

  setup();
}
