//jinling  yamen.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ���ǵ�֪�����š����Ĵ����϶�����ڴ��ͭ�����������⣬
���ɷǷ������ſ���������ʯʨ��������צ���㲻���е�һ���ļ£����Ǹ�
���뿪�ɡ�
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "east" : __DIR__"beijie1",

]));

        set("no_clean_up", 0);

set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
