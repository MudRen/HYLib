// Room: /d/yandang/river
inherit ROOM;

void create()
{
  set ("short", "��������");
  set ("long", @LONG
��������ˮ,�����뺣,���紵��,����΢΢�Ľ�ˮ����Ϣ,�������
�ݰѽ�����׺�÷�������,���ĶԶ˾��Ǳ��ұ���֮��---����.
LONG);

  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shulin",
]));
  setup();
}
