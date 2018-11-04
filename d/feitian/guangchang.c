// Room: /d/city/guangchang.c

inherit ROOM;

void create ()
{
  set ("short", "����㳡");
  set ("long", @LONG
���������ľ���������,һ���ܿ����Ĺ㳡,һЩ��Ʀ,��ʿ�������й�.
�������������ҵ������������.�ڹ㳡������һ��ӣ����(tree).ÿ��
ӣ��ʢ����ʱ�����˾�������Ⱦ��ͻ�,Ҳ�Ǿ�ӣ������,ӣ���ϵ���
Ҷ(leaf)�ǳ�ï��,�м�ֻС�������������ȥ.�����Ա���һ��������
����(sign).
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/dipi" : 1,
  __DIR__"npc/yiren" : 1,
  __DIR__"npc/wushi" : 1,
]));
  set("peach_count", 30);
  set("item_desc", ([ /* sizeof() == 3 */
  "sign" : "�밮��������ľ������������ط���    --������ʾ
",
  "leaf" : "��Ҷ���ɵع������ϣ�����ȥ�������ժ������
",
  "tree" : "һ�ô�����֦Ҷï�ܣ�����������������֦ͷ���������ӣ��Ѿ����Ҫ�������ˡ�
",
]));
  set("stick_count", 5);
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ximen",
  "north" : __DIR__"beijie",
  "south" : __DIR__"haigang.c",
  "east" : __DIR__"jiedao1",
]));
  set("outdoors", "����������");
  set("no_sleep_room", 1);

  setup();
  replace_program(ROOM);
}
