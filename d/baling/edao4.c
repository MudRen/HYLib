// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
����Ͽ���ֳ���ȪϿ������Ͽ,��������ɽ��,ȫ��2.7ǧ��.��ʱϿ
�ڽ�����Ȫ�أ���Ϊ��������������Ͽ��ˮ�������ڣ����е���������
���磻Ͽ��������಻��200�ף�����ͦ�������絶�丫����Ͽ��֮��
��Ȫ����ӿ���Ƹ��������ɫ������ΪС��Ͽ֮�ڡ�
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"edao5",
		"northwest" : __DIR__"eroad5",
                "east" : __DIR__"ximen",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


