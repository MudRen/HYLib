//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��վ���������Ķ��������µ���·�ƺ��������ϱ��Ĵ�������
����ֻ�����۵�㣬���ǲ����̨���񷤡�·�߾����������֣�̨��
����¥�����֡�������ȥ�Ĳ�·ͨ�����������Բ�����·����ֱ��
���ڳǡ�
LONG
);

	set("exits", ([
		"northwest" : __DIR__"minov64",
		"southwest" : __DIR__"minov72",
		"south" : __DIR__"minov71",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
