// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
ʯ�����Ե�ʯ����ԭ������ۻʵ�ʨ�ӣ���������置�������
���գ�Ȼ��������֮�׵����룬���������书��ʢ���������ֵ�ս��
����������ͷţβ���������ǵ���ޡ�
LONG
);
    set("exits", ([
       "north" :__DIR__"shidao1",
       "south" :__DIR__"shendao",
]));
    setup();
    replace_program(ROOM);
}
