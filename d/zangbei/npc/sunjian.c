#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�｣",({"sun jian","sun"}));
//      set("title",HIY"�ջ�԰"NOR);
        set("title",HIR"�������"NOR);
        set("long","
�｣��ò���ã�Ũü���ۣ����ϵ�Ƥ����ɹ������ͭɫ�����۾��������ʱ���������
ȥ�����ˣ�Ҳû������ȥ�����ˡ��������ֱ������｣�磬 ���������⡰�硱 ���е�
Ů���������Ծ��Լ������硱��ȥ��������Ը�Լ����Ϲ���һ��һ��Ů��������Ҳ����
����һ���������壬���㽫�Լ����ϵ��·������������˴�Ҳ������ϧ��\n");
        
        set("gender","����");
        set("group","juyuan");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",45);
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "�ϲ�": "�ϲ������Ҹ��ס�\n",
                "�ϲ�": "�ϲ������Ҹ��ס�\n",   
           ]));
        
//      set("death_msg",CYN"\n$N��Ц�ŵ�������ȫ��ȥ���ɣ���������á���\n"NOR);        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
                "\n�｣Ҳ����վ��̫���ˣ������Ե��е㲻�ͷ���\n",
        }) );                   
        
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
} 
void init() {
        ::init();
        add_action("do_answer","answer");
}  
int do_answer(string arg)
{
        switch (arg) {
                case "���㴨":
                case "lv xiangchun":    command("say �ã���ȥ�ɣ�\n");
                                        this_player()->set_temp("zangbei/see_lv",1);
                                        break;
                case "�ϲ�":
                case "����":          command("say �Ҹ���������æ�����������ɡ�\n");
                                        break;
                case "sun jian":
                case "�｣":            if (this_player()->query("gender")=="Ů��" && this_player()->query("age")<40
                                                && this_player()->query("age")>16)
                                                message_vision(CYN"$N�պ�һЦ�������ڲ���ʱ�򣬵��Ұ�������°����˰ɡ���\n"NOR,this_object());
                                        else message_vision(CYN"$N��Ц������������ƽ�������Һ��£�\n"NOR,this_object());
                                           break;
                case "½����":
                case "lu mantian":
                case "����":
                case "han tang":        command("say ��������æ�����������ɡ�\n");
                                        break;
                default:                command("say ����û������ˡ�\n");
        }
        return 1;               
}     
