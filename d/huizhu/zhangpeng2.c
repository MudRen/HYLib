// Room: /d/huizhu/zhangpeng2
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
���Ƕ��ݲݼӹ���ţƤ���񣬵���������ձ�ӣ������Ѿ����ƾ��ˣ�
����ϴˢ�úܸɾ���һ�ߵ������Ϸ��Ÿ�СС�ĺ�ɫ���ӣ�����֮�⣬��
���о�һ������ˮ��������ˮ�롣
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"buluo2",
]));
  setup();
  replace_program(ROOM);
}
