inherit ROOM;

void create()
{
	set("short", "��Ҵ�Ժ");
	set("long", @LONG
�������ׯ԰����ǰ���һ�������Ĵ�Ժ����Ժ����ֲ��
���໨�ݣ���ɽˮ�أ���¥��̨���ǳ�������Ժ�ڴ�ɨ�÷ǳ�
�ɾ���������һ��������ϱ�Ҳ��һ��С�ݡ�
LONG);
	set("exits", ([
  		"west"  : __DIR__"miaojia_men",
  		"east"  : __DIR__"miaojia_zhengting",
  		"north" : __DIR__"miaojia_chufang",
  		"south" : __DIR__"miaojia_chaifang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
