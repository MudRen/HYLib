// Room: /d/hainan/wenquan 
inherit ROOM; 
 
void create ()
{
  set ("short", "��Ȫ��");
  set ("long", @LONG
���������������ס���������.����ߴ�������ˮ����������
�л�������ļ�����.��ֻ��żȻ�������ǵ���Ӱ.�¶����е�Ȫˮ��
����ůů��.ˮ����Ʈ�����һ��Ļ���.
LONG);

  set("bath_room", 1);
  set("bath_equipment", "��Ȫ");
  set("no_fight", 1);
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"taotree3",
]));

  setup();
}
