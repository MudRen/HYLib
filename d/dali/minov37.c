//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��ϼɽ");
	set("long", @LONG
��ϼɽ�������ƺ���ɽ�����㣬��������������ͺ���ɽɫ����
��Ϊ֮�㵹��������ʫԻ��
      ��ϼ������������
      ���ƺ�ˮ�����⣬
      ���캬�����ϴ䣬
      Զɽ�ͱ�Ħ��ԣ�
      ˮ��ɽɫ���ӳ��
      �������Ʊ��쾻��
LONG
        );

	set("exits", ([
		"westdown" : __DIR__"minov36",
		]));

	set("objects", ([
		__DIR__"npc/youke1.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
