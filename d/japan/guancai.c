// Room: /d/japan/guancai
inherit ROOM;

void create()
{
  set ("short", "�ײ���");
  set ("long", @LONG
�ս���,��ʹ��˸�ͻ,������������˴��СС�Ĺײ�,�ڷ������
��,������Щ����,��Ӱ�������лζ�,����ʮ�ֲֿ�.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jiedaoe2",
]));
  setup();
}
