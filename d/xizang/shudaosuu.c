 inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�Թ����·���У�һ��ʫ�����ʫԻ������Ϸ��Σ�����գ����֮����������
�죡������ɽӳ��ˮ��һ·�������ۣ�������̲������ʯջȮ������Գ�񰧺Ź�
ľ���죬���;����������̡���˰��������ֳ�����·Ϊ��������������С�
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"shudao1",
]));
        set("outdoors", "guanwai"); 
        set("coor/x",-800);
    set("coor/y",-650);
        set("coor/z",0);
        setup();
}
