// room1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����г����ª�����������࣬��ɨ��ǬǬ������һλ����������
ձ������������ꡣ���ܷ���Щ����м��С��ľ���ϸ��˼����ߺ���
Ʈ���������˵�������
LONG
        );
        set("exits", ([
            
            "west" : __DIR__"shop",
        ]));
        

        setup();
        replace_program(ROOM);
}
