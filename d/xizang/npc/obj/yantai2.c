 inherit ITEM;
void create()
{
        set_name("�»�ɫ��̨", ({ "yellow yantai", "�»�ɫ��̨", "yantai" }) );
        set_weight(1300);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������»�ɫ��̨��
��������Ө�࣬���ϰ���ʯͷ������ɫ������һ����Ȫͼ����������������Ƶġ�\n");
                set("value", 1000);
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
        }
        
} 
void init() {
        add_action("do_look", "look");
} 
int do_look(string arg) {
        object me;
        
        me = this_player();
        if (!arg || (arg != "yantai" && arg != "yellow yantai")) {
                return 0;
        }
        if (environment(me)->query("mingxuan")) {
                if (NATURE_D->is_day_time()) {
                        tell_object(me, "\n�����һ������̨�ϵ�̵���Ȫͼ��Ȼ����ǰ��ɫ��ȫ��ϡ�\n");
                        tell_object(me, "ֻ����̨�ϻ��������ƺ���Ȫˮ����µ����Ҷ����Աߵ�һ����ǡ�\n");
                        me->set("marks/��ɽ����Ȫ", 1); 
                } else {
                        tell_object(me, "\n�������Ȫͼ�����ܾ�ɫ��Щ���ƣ����Ǻڰ�֮�п��������\n");
                }
        }
        return 0;
}    
