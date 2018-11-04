// dong2.c
// bbb 1997/07/16
// COOL@SJ,9808

inherit ROOM;

string look_yuxiang();
string look_zi();
string look_shoe();
string look_left();
string look_right();

void create()
{
    set("short", "����");
        set("long", @LONG
��ǰͻȻһ����һ����װ��Ů���ֳֳ����������׼��������š�ϸ��
֮�£�ԭ����һ������yuxiang)������д������֣�zi�����ʷ�Ʈ�ݣ���
�Լ�ǿ����������д�ɣ��������������ˮ����ˮ������ˮ������ӳ��ʯ��
�бȵ�һ��ʯ������������
LONG
        );

        set("exits", ([
                "out" : __DIR__"dong1",
        ]));

        set("valid_startroom",1);
        
        set("item_desc",([
                "left"          :       (: look_left :),
                "right" :               (: look_right :),
                "zi"            :       (: look_zi :),
                "yuxiang"       :       (: look_yuxiang :),
        ]));

        setup();
}


void init()
{
        add_action("do_ketou", "ketou");
}

int do_ketou(string arg)
{
       object me;
       me=this_player();

       if (!me->query_temp("lbwb1/yuxiang")) return 0;
       if ( me->query("dali/fail") > 3) return 0;

       if( !arg || arg != "yuxiang" ) return 0;
        
       if( arg=="yuxiang" ) {
           message_vision("$N�������ţ��������������������ͷ����\n", this_player());
           if(!me->query_temp("lbwb1/left") || !me->query_temp("lbwb1/right")) {
                write("���������һ��ͷ����ȥ���ƺ������������ţ�left)���ҽţ�right)������֡� \n");
                return 1; 
           }
           if( me->query_temp("ketou_trigger") > 15 
            && me->query_temp("ketou_trigger") < 17 ) {
               message_vision("$N���������ϵı����������ѣ��������ֽ�ȥ������ʲôҲû�У������Ѿ���ȡ���ˡ�\n",me);
               me->delete_temp("lbwb1");
               me->delete("ketou_trigger");
               return 1;
           }
           if (!me->query("dali/meet_dy1") 
            || !me->query("dali/pass")) {       
               me->set_temp("duanyu/find1",1);
               me->add_temp("ketou_trigger", 1);
               return 1;
           }       
           return 1;
       }
}


string look_left()
{ 
       object me;  
       me=this_player();
       me->set_temp("lbwb1/left",1);
          return "���װٱ飬�������ߡ�\n";
}

string look_right()
{ 
       object me;  
       me=this_player();
       me->set_temp("lbwb1/right",1);
          return "���������������޻ڡ� \n";
}

string look_zi()
{
       return "���������£��˼�����Ҳ -- ��ң��Ϊ��ˮ���顣\n";
}

string look_yuxiang()
{    
       object me;  
       me=this_player();
       me->set_temp("lbwb1/yuxiang",1); 
          return "����һ�������ɵ�����������һ���С�����ϵ��Ƴ���΢΢�������������һ������ӨȻ�й⣬��ɷ��  \n";
}
