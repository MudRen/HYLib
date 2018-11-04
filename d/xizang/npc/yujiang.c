 // jademaker.c
#include <ansi.h>
int stone();
inherit NPC; 
void create()
{
        set_name("�޴��", ({ "luo", "jade maker", "��" }) );
        set("gender", "����" );
        set("title", "��ʯ��");
        set("age", 55);
        set("long", "����һ˫�������۾�����˫�ۿ��Էֱ���ʯ������
������һ˫���֣�����˫������԰���ʯ��������������\n");
        set("combat_exp", 140);
        set("str", 30);
        set("env/wimpy", 10);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������������ϴ�С�������ı��ݴ�ζ����������\n",
                "�����������������ɫ��ʯ����ɫ��ʯ���ѵ���ֻ��һ����˵�𣿡�\n",
        }) );
        set("inquiry", ([
                "���ݴ�":       "������ûʲô���ã�����ϲ����Щ�ò衣"
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
void init(){
        int i;
        object me;
    
        me = this_player();
        i = me->query("marks/Timeyantai");
//      4320
        if ( time() - i > 4320 && i != 0) {
                call_out("yantai", 1, me);   
        }
}  
int stone(){
   object me;
        me = this_player();
        if(this_object()->is_fighting() || this_object()->is_busy()) {
                return 0;
        }
        message_vision(YEL"$N΢΢һЦ��������˵������������ı�ʯ���κ�������ܵõ����е�һ
�֣����ܴ��еõ�������������������������¶���Ҳֻ����˵�ģ����Ƴ���
��������������Ե��Ƕ�ȥ����һ�¡���\n"NOR, this_object());
        if(me->query("stone_mark")){
                message_vision(HIG"\n$N���������д�˵����ɫ��ʯ���Խ��һ�屣���������ˡ�\n"NOR, this_object());
        }
        return 1;       
} 
void yantai(object me) {
        object obj;
    
        if (!random(300)) {
                message_vision(YEL"��ʯ��̾�˿�����$n˵���������ˣ���Ҳ�������ˣ���̨�����ˣ������ҼҴ���̨��\n"NOR,
                        this_object(), me);
                message_vision("���͸���ɡ���\n", me);
                obj = new(__DIR__"obj/yantai2");
        } else {
                message_vision(YEL"��ʯ��˵��������λ" + RANK_D->query_respect(me) + "�����Ǽӹ��õ���̨��\n"NOR, 
                        this_object(), me);
                if(me->query("marks/Coloryantai") == "��") {
                obj = new(__DIR__"obj/yantai");
                } else if (me->query("marks/Coloryantai") == "�Ϻ�") {
                        obj = new(__DIR__"obj/yantai1");
                }
        }
        obj->move(me);   
        me->delete("marks/Coloryantai");
        me->delete("marks/Timeyantai");
        me->delete("marks/��ʯ�ӹ�");
}   
int accept_object(object who, object ob){
        object me,dog;
        string color;
        
        me = this_player();
   if( ob->query("����")){
                message_vision("$N���Ų�Ҷ�ŵ����ӵ��������ᣬ¶�������Ц�ݡ�\n", this_object(), me);
                message_vision("$N˵��������л��λ" + RANK_D->query_respect(me) + 
",���಻�ţ�������ڼӹ���ʯ�������������ൽ����֪һ������ \n", this_object(), me);
                me->set("marks/��ʯ�ӹ�", 1);   
        } else if( ob->query("��̨��") == 1 ){
                message_vision("$N������" + ob->name() + "ߵ�����£�Ц��:������ �����������һ���Ϻõ���̨����\n", this_object(), me);
                if(me->query("marks/��ʯ�ӹ�")) {
                        message_vision("$N˵��������λ" + RANK_D->query_respect(me) + "�������ȡ��̨�ɡ���\n", this_object(), me);
                        color = ob->query("color");
                        me->set("marks/Timeyantai", time());
                        me->set("marks/Coloryantai", color);
                }else {
                        message_vision("����˵�������������������θ�ڲ��ã����ٽӻ��ˡ���\n", this_object(), me);
                        return 0;
                }
        } else if (ob->name()==YEL"������"NOR || ob->name()==GRN"��ɽ��"NOR) {
                message_vision("$N˵���������Ϻõ����裬���������ڵ���ʱ���ƺ����ˣ�������ඡ���\n",this_object());
                return 0;
        } else if (ob->name()=="�����") {
                message_vision(CYN"$N�޵�һ��˵����ı�ƺ���֮ͽ�����ҹ���ԶԶ�ġ���\n"NOR,this_object());
                message_vision(CYN"$N���������ڣ���������һֻ���򹷡�\n"NOR,this_object());
                command("say ���ӣ����Ҹ�����ȥ��");
                if (!dog=present("shepherd dog",environment(this_object()))) {
                        dog=new(__DIR__"sheepdog");
                        dog->move(environment(this_object()));
                }
                dog->fight_ob(me);
                me->fight_ob(dog);
                return 0;       
        }else {
                message_vision("����ҡͷ˵�����Ҳ���Ҫ�������\n", me);
                return 0;
        }       
        return 1;
}   
