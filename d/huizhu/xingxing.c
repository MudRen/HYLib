// Room: /d/huizhu/xinxin
inherit ROOM;

void create()
{
  set ("short", "����Ͽ");
  set ("long", @LONG
ת��֮��,ʯ��Խ��Խ��,һ���ſ�,ֱ���ȥ,ɽʯ����������
�ƺ����б�����أ��ٱ���ʱ�������ͱ��м�¶��һ������,�Ǳ�
�Ǹ���ͻؽ�֮��Ľ�ͨ�׵�����Ͽ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xianei",
  "northeast" : __DIR__"shamo",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
