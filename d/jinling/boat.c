// boatin.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ڽ��С��ҹ����ݵس���С��, ����ȻҲ��С, ������ȴҲ�׵���
�������, ���½�ƮƮ, �������С�
LONG);

        set("objects", ([
			 __DIR__"npc/boater1" : 1
        ]) );
        setup();
}

