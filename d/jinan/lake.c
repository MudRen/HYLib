 inherit ROOM;
void create()
{
    set("short", "������");
        set("long", @LONG
������ɻ���������һ��ɽɫ��Ǻ������������µĴ�����Ϊ������ʤ֮�ף�
������ɫ���컶��ˡ����ź���������������֦���ݣ�����������б�����գ�ӳ
�ð�����졣��������ĺ�������ˮ���ɣ����ۺ��ϣ��ƺ����г��鷳�¶���һ
һ��ȥ��̧����ȥ���̲�ƺ������������ˮ�����������Ƶ�ɽ����Լ�ɼ���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"street2",
  "northeast" : __DIR__"road1",
]));
        set("objects", ([
        "/clone/npc/man" : 2,
        	__DIR__"npc/surong" : 1,
                        ]) );
        set("resource/water",1);
        set("liquid", (["container":"������"]));
    set("outdoors", "jinan");
    set("coor/x",50);
    set("coor/y",1950);
    set("coor/z",0);
        setup();
} 
/*
void init()
{
        string msg;
        msg = "asfsdfsa";
        message_vision(msg,this_player());
        message_vision(capitalize(msg),this_player());
} 
*/
