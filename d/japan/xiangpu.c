// Room: /d/japan/xiangpu
inherit ROOM;

void create()
{
  set ("short", "����ԭ������");
  set ("long", @LONG
����һ��������.ר�Ž������˵ļ���.������˵��Ϊ���ֵĹؼ���
���ȳ�Ϊһ��������.$#%^^&@#.....����Ҳʱ���������˱���.����Ȥ��
Ҳ�����³�.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jiedaos2",
]));
  setup();
}
