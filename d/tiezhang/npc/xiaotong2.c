inherit NPC;
#include <ansi.h>
int give_tools();
void create()
{
        set_name("Сͯ", ({"xiao tong", "xiao", "tong", }));
        set("long", "����һλδͨ���ʵ����꣬���Ϲ����������Ц��\n");
        set("gender", "����");
        set("attitude", "peaceful"); 

        set("age", 10);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);
        set("combat_exp", 500);
        set("score", 100);
        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("strike", 10);
        set_skill("parry", 10);

        set("inquiry", ([
                         "����" : (: give_tools :),
                         "tools" : (: give_tools :),
                  ]) );
        setup();
        carry_object(__DIR__"obj/huiyi")->wear();

}
     
int give_tools()
{
       object tools,ob,me;
       me = this_object();
       ob = this_player();
//     if(!((ob->query_temp("job_name")=="���ݾ�" )
//       ||(ob->query_temp("job_name")=="��կ��" )
//       ||(ob->query_temp("job_name")=="��ľ" ))){
       if( !ob->query_temp("job_name")){
          say (CYN"С��˵������û���������ɣ�����Ҫʲô���ߡ�\n"NOR);
          return 1;
          } 
       if(ob->query_temp("mark/����")){
          say (CYN"С��˵�������Ȱѹ��߻��ˣ����칤�߰ɡ�\n"NOR);
          return 1;
          } 
       if(ob->query_temp("mark/����")){
          say (CYN"С��˵�����㻹û�������»�ɣ�����Ҫʲô���ߡ�\n"NOR);             
          return 1;
          }  
          say(CYN"С��˵������Ȼ���Ѿ����˻�Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ�\n"NOR);
          message_vision("$N����$nһ�ѹ��ߡ�\n", me, ob);
       if(!(ob->query_temp("job_name")!="���ݾ�")){
         tools = new(__DIR__"obj/tiechan");
         tools->move(this_player());
         say(CYN"С��˵�������ݾ����ڹ㳡���ɽ·�ϣ��Է��������ɺ͹ٸ������ư����˺�Ѱ��(dig xianjing)��\n"NOR);
         } 
       if(!(ob->query_temp("job_name")!="��կ��")){
         tools = new(__DIR__"obj/tiechui");
         tools->move(this_player());
         say(CYN"С��˵������ɽ�Ŷ����կ���޲�һ�£��Ѿ��кܳ�ʱ��û��ȥ�޲���կ����(repair zhailan)��\n"NOR);
         }
       if(!(ob->query_temp("job_name")!="��ľ")){
         tools = new(__DIR__"obj/tiefu");
         tools->move(this_player());
         say(CYN"С��˵��������ָ��ɽ����һƬ�����֣�������ȥ��ľ�ɣ�������˵��������Ұ�ޣ�Ҫ���İ�(fa mu)��\n"NOR);
           } 
          say(CYN"С��˵�����������������⻹���ߣ��ٵ��������ﱨ��(task ok)��\n"NOR);
        ob->set_temp("mark/����",1);
        return 1;
}

int accept_object(object me, object obj)
{
      object ob;
      me=this_object();
      ob=this_player();
     if(!(ob->query_temp("mark/����")||ob->query_temp("mark/����")
        ||ob->query_temp("mark/����")))
        {
        say(CYN"С��˵���㻹û��ɹ�������ô�ͻ����������ˣ�͵����\n"NOR);
                 return 1;
              } 
     if ((obj->query("id")!="tie chui")&&(obj->query("id")!="tie chan")&&(obj->query("id")!="tie fu"))            
        {  
        command("say �㻹�����˰ɣ��Ҵ�û�з����������ߡ�\n");
                 return 1;
              }
     if((ob->query_temp("job_name")=="ɽ·���ݾ�" )||(ob->query_temp("job_name")=="ɽ�Ŷ���կ����կ��")
          ||(ob->query_temp("job_name")=="��ָ�������ַ�ľ" ))
            {  command("shake");
               command("say ��û�з���������������ǲ��ǻ����ˣ�\n");
                           return 1;
                     }
              else {
               command("nod");
               command("say ���ͣ����ͣ��´��ٺúøɰ�!");
               ob->set_temp("mark/����",1); 
               call_out("destroying", 1, me, obj);           
               return 1;
              }
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
