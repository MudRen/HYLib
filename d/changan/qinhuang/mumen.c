// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "�ػ���");
    set("long", @LONG
�߳�ĹѨ����ǰ��Ȼ���ʣ�����ƴ�ĵ��¹����ȴһ�㶼��
���ú͵�����ʲô���𣬶�����Ƕ������ɢ����ӫ��ġ����ǡ�����
�����㿴�����ܵľ����ˡ�
LONG
);
    set("exits", ([
       "east" :__DIR__"shendao",
]));
    setup();
    replace_program(ROOM);
}
