// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "��Ͽ");
	set("long", @LONG
��Ͽ������Ͽ,��������������.����Ͽ�����ͻأ,��ʯ���
�ͱ���������.���Ӳ���.����Ͽ����ɹ۵�һ�Σ�����һ���ػ�
���۵Ļ��ȣ�����ʫ�����⡣��ϿϿ������ػ����ۣ������
�����࣬���������ƣ���ɫ����֮������һ������ʤ�յĻ��ȡ�

LONG
	);

	set("exits", ([
		"southwest" : __DIR__"shandao",
                "northeast" : __DIR__"edao8",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


