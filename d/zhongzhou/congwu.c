inherit ROOM;

void create()
{
        set("short","�����ھ�");
        set("long", @LONG
��������ݵ�һ���ھ֣���������һ�˶�ߵ��㰸��˫��
������λ��ͷ��ͤ����Ļ�ͷ�������������ھֵ�����ͷ����
�����ұ��������ݳǵ��Ķ����֡�
LONG);

        set("exits", ([
                "east" : __DIR__"wendingbei4",
                 
        ]));

        set("objects",([
                __DIR__"npc/dudajin":1,
        ]));
        set("coor/x", -240);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
