// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "���");
    set("long",@LONG
��һ��Ƭ�ռ�ĸ߶Ȳ����Ǻܸߣ����������棬����ҹ�գ�����
��С���͵���Ϊ����֮�ã����������������ڿ�Ұ֮�п�ҹ�ա�����
���ϣ���һ���൱�����ĺ�������ˮ��������������������ȴ��----
��ˮ������
LONG
);
    set("exits", ([
        "north" :__DIR__"dadian2",
]));
    setup();
    replace_program(ROOM);
}

