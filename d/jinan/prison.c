 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������������������ľ���ս�����ֺ��η���ԼĪ���ɼ�����һ���ʯ�ݣ�
ǽ�ڶ���һ���ֲڵĴ�ʯ����������Ҳ�Ǵ�ʯ���̳ɣ��Ѿ��ܶ���û����ɨ��
���Ե��ϱ�ؾ������м���๸����ˮ��ǽ��һͷ����һֻ��Ͱ�������ŵ���
���ǳ�����ù����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"andao2",
]));
        set("objects", ([
        __DIR__"npc/jin9" : 1,
                        ]) ); 
    set("coor/x",100);
    set("coor/y",1880);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}     
