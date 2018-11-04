 inherit ROOM;
#include <ansi.h> 
int closedoor(); 
void create() 
{
        set("short", "��Ժ");
        set("long", @LONG
��ҵĿ��˾��������١������ǳԹ���̫̫�������ĺ���ʨ��ͷ����������
����������߳�Ժ��ʱ���������˶�����Ժ�����ֵĻ��������䡣��������
������Ц�ţ�Ҳ����������ȷ���ֻ����������Ⱥã�ÿ���＾�ջ�ʢ������С��
����С���ͻ��ڻ�����׷����ˣ��
LONG
        );
        set("exits", ([ 
                "west":         __DIR__"mroom",
        ]));
        set("item_desc", ([
                "�ջ�": "�����＾��Ժ����ľջ��а��˶�ߣ�Ѥ�ö�ʡ�\n",
                "flower": "�����＾��Ժ����ľջ��а��˶�ߣ�Ѥ�ö�ʡ�\n",
        ]));
        set("objects", ([
                __DIR__"npc/mafangzhong":       1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",-1020);
        set("coor/y",140);
        set("coor/z",0);
        setup();
}  
void init() {
        add_action("do_pull","pull");
}   
int do_pull(string arg) {
        object me=this_player();
        object ma;
        
        if (arg== "flower" || arg == "�ջ�") {
                if (ma=present("ma fangzhong",this_object())) {
                        tell_object(me,"�������ֵ�ס�㣬Ц������˵�������ִݻ���̫ɷ�羰�˰ɡ���\n");
                        return 1;
           }
                message_vision(YEL"
$N�������䣬ץס������ïʢ���Ǵؾջ�ʹ������һק���ջ�����������
������һ�������������֮�£���Ȼ������һ��������Ĵ󶴣�\n"NOR,me);
                set("exits/down",__DIR__"tunnel1");
                call_out("closedoor", 15);
                return 1;
        }
        return notify_fail("�����/��ʲô��\n");
}    
int closedoor () {
        if (query("exits/down")) delete("exits/down");
        return 1;
}        
