//Cracked by Kafei
// Room: /d/xixia/qingong.c

inherit ROOM;

void create()
{
	set("short", "�޹�");
	set("long", @LONG
����������Ļʵ۵��޹���һɫ�İ���ذ壬��ɫ��ɴ�ʣ�����
�ǻʵ۵���齣�齱���һ�Ű��ϻ�Ƥ����̤��, ǽ�Ϲ��Ű������䵶��
��˵����ެ�Ĺ�Ʒ����������������ֵҹ�ظ���ƫ�����ǽ���з�
��ӥ�˳�ľ޻���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"piandian2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
