//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��ɺӱ�");
	set("long", @LONG
��ɺ��������������ӹ���խ��ˮ���ļ������Ѷɹ���ֻ��Զ��
���β��к�������������д��ɺӡ��˴��Ǻӹ�ת���ǳ̲��ˮ����
���������Կɼ����Ϻ�ˮ��ӿ��ȥ���԰����������ɼ����ϱ�ɽ����
��ʯ�ǡ�
LONG
        );

	set("exits", ([
		"southup" : __DIR__"minov81",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
